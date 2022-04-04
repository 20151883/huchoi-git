package jpabook2.jpashop2.domain.item;

import jpabook2.jpashop2.domain.Category;
import jpabook2.jpashop2.exception.NotEnoughStockExeption;
import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

@Entity
@Getter
@Setter
@Inheritance(strategy = InheritanceType.SINGLE_TABLE)
@DiscriminatorColumn(name = "dtype")
public abstract class Item {//추상클래스로 만듦
    @Id @GeneratedValue
    @Column(name = "item_id")
    private Long id;

    @ManyToMany(mappedBy = "items")
    private List<Category> categories = new ArrayList<>();

    private String name;
    private int price;
    private int stockQuantity;

    //==비지니스 로직==//엔터티 안에 비지니스 로직을 넣는게 좋다고 얘기하심

    /**
     * stcok 제고 증가
     * @param quantity
     */
    public void addQuantity(int quantity){
        this.stockQuantity += quantity;
    }

    /**
     * stock 제고 감소
     */
    public void removeStock(int quantity){
        int result = this.stockQuantity - quantity;
        if (result < 0){
            throw new NotEnoughStockExeption("need more stock");
        }
        this.stockQuantity = result;
    }
}
