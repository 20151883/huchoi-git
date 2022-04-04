package hello.core.discount;

import hello.core.AppConfig;
import hello.core.member.Grade;
import hello.core.member.Member;
import hello.core.member.MemberService;
import hello.core.member.MemberServiceImpl;
import hello.core.order.Order;
import hello.core.order.OrderService;
import hello.core.order.OrderServiceImpl;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.*;

class RateDiscountPolicyTest {

    RateDiscountPolicy rateDiscountPolicy = new RateDiscountPolicy();
//    MemberService memberService = new MemberServiceImpl();
//    OrderService orderService = new OrderServiceImpl();

    MemberService memberService;
    OrderService orderService;

    @BeforeEach
    public void beforeEach(){
        AppConfig appConfig = new AppConfig();
        this.memberService = appConfig.memberService();
        this.orderService = appConfig.orderService();
    }

    @Test
    @DisplayName("VIP는 10%할인이 되어야한다")
    void vip_o() {
        //given
        Member member = new Member("memberA", 1L, Grade.VIP);
        this.memberService.join(member);
        //when
        Order order = this.orderService.createOrder(1L, "itemA", 10000);
        //then
        assertThat(order.getDiscountPrice()).isEqualTo(1000);
    }

    @Test
    @DisplayName("VIP가 아니면 10%할인이 적용되면 안된다")
    void basic_o() {
        //given
        Member member = new Member("memberA", 1L, Grade.BASIC);
        this.memberService.join(member);
        //when
        Order order = this.orderService.createOrder(1L, "itemA", 10000);
        //then
        assertThat(order.getDiscountPrice()).isEqualTo(1000);
    }
}