package jpabook2.jpashop2.domain;

import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;

@Entity
@Getter @Setter
public class Delivery {
    @Id @GeneratedValue
    @Column(name = "delivery_id")
    private Long id;

    @OneToOne(mappedBy = "delivery", fetch = FetchType.LAZY)
//    @Column(name = "orders")
    private Order order;

    @Embedded
    private Address address;

    @Enumerated(value = EnumType.STRING)//ORDINAL은 유지보수를 힘들게 만든다
    private DeliveryStatus status;
}
