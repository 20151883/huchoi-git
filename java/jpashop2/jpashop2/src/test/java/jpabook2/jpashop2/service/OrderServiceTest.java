package jpabook2.jpashop2.service;

import jpabook2.jpashop2.domain.Address;
import jpabook2.jpashop2.domain.Member;
import jpabook2.jpashop2.domain.Order;
import jpabook2.jpashop2.domain.OrderStatus;
import jpabook2.jpashop2.domain.item.Book;
import jpabook2.jpashop2.domain.item.Item;
import jpabook2.jpashop2.exception.NotEnoughStockExeption;
import jpabook2.jpashop2.repository.OrderRepository;
import org.assertj.core.api.Assertions;
import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;
import org.springframework.transaction.annotation.Transactional;

import javax.persistence.EntityManager;

import static org.junit.Assert.*;
import static org.junit.Assert.assertEquals;

@RunWith(SpringRunner.class)
@SpringBootTest
@Transactional
public class OrderServiceTest {

    @Autowired
    EntityManager em;
    @Autowired
    OrderService orderService;
    @Autowired
    OrderRepository orderRepository;

    @Test
    public void 상품주문() throws Exception{
        //given
        Member member = new Member();
        member.setName("회원1");
        member.setAddress(new Address("seoul", "42", "424242"));
        em.persist(member);

        Item book = new Book();
        book.setName("jpa");
        book.setPrice(10000);
        book.setStockQuantity(10);
        em.persist(book);
        //when
        Long orderId = orderService.order(member.getId(), book.getId(), 2);

        //then
        Order getOrder = orderRepository.findOne(orderId);
        assertEquals("상품주문시 상태는 ORDER", OrderStatus.ORDER, getOrder.getStatus());
        assertEquals("주문상품의 수와 종류가 맞아야합니다", 1, getOrder.getOrderItems().size());
        assertEquals("주문가격은 가격 * 수량이다", 2 * 10000, getOrder.getTotalPrice());
        assertEquals("재고수량이 맞아야한다.", 8, book.getStockQuantity());
    }

    @Test(expected = NotEnoughStockExeption.class)
    public void 상품주문_재고수량_초과() throws Exception{
        //given
        Member member = getMember();
        Item book = getItem();
        //when
        orderService.order(member.getId(), book.getId(), 11);
        //then
        fail("재고수량 부족 예외가 나와야한다.");
    }

    private Item getItem() {
        Item book = new Book();
        book.setName("jpa");
        book.setStockQuantity(10);
        book.setPrice(10000);
        em.persist(book);
        return book;
    }

    private Member getMember() {
        Member member = new Member();
        member.setName("memberA");
        member.setAddress(new Address("seoul", "123", "42"));
        em.persist(member);
        return member;
    }

    @Test
    public void 주문취소() throws Exception{
        //given
        Member member = getMember();
        Item book = getItem();
        Long orderId = orderService.order(member.getId(), book.getId(), 2);
        //when
        orderService.cancelOrder(orderId);
        //then
        Order gerOrder = orderRepository.findOne(orderId);
        assertEquals("주문취소시 상태는 cancle ", OrderStatus.CANCEL, gerOrder.getStatus());
    }

    @Test
    public void 주문수량초과() throws Exception{
        //given

        //when

        //then
    }
}