package jpabook.jpashop.domain;

import org.hibernate.annotations.Immutable;

import javax.persistence.*;

import static javax.persistence.FetchType.LAZY;

@Entity
public class Delivery  extends BasicEntity{

    @Id @GeneratedValue
    private Long ID;

    @OneToOne(mappedBy = "delivery", fetch = LAZY)//db랑 매핑을 위한게 아니라 객체참조관계를 위한것임
    private Order order;

//    private String city;
//    private String street;
//    private String zipcode;
    @Embedded
    private Address address;
    @Enumerated(value = EnumType.STRING)
    private DeliveryStatus deliveryStatus;

    public Long getID() {
        return ID;
    }

    public void setID(Long ID) {
        this.ID = ID;
    }

    public Order getOrder() {
        return order;
    }

    public void setOrder(Order order) {
        this.order = order;
    }

    public Address getAddress() {
        return address;
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    public DeliveryStatus getDeliveryStatus() {
        return deliveryStatus;
    }

    public void setDeliveryStatus(DeliveryStatus deliveryStatus) {
        this.deliveryStatus = deliveryStatus;
    }
}
