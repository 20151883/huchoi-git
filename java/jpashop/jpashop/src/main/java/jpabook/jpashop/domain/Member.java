package jpabook.jpashop.domain;

import javax.persistence.Column;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import java.util.ArrayList;
import java.util.List;

public class Member {

    @Id@GeneratedValue
    @Column(name = "member_id")
    private Long id;

    private String name;

    private Address address;

    private List<Order> orders = new ArrayList<>();
}
