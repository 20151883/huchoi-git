package jpabook.jpashop.domain;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

@Entity
public class Member  extends BasicEntity{
    @Id @GeneratedValue
    @Column(name = "MEMBER_ID")
    private Long id;

    @Column(name = "USERNAME")
    private String username;

    @OneToMany(mappedBy = "member")
    private List<Order> orders;

    @Embedded
    private Address address;

    @ElementCollection
    @CollectionTable(name = "FAVORITE_FOOD", joinColumns =
        @JoinColumn(name = "MEMBER_ID")
    )
    @Column(name = "FOOD_NAME")//저쪽 테이블 만들때 컬럼명을 설정해준거(어짜피 저쪽테이블에 Member FK랑 String PK밖에 없음....) <- 컬럼이 딱 하나일때 가능한 거.
    //즉 저쪽 테이블 만들때의 설정을 이 @Column을 통해 해준거!
    private Set<String> favoriteFood = new HashSet<>();

    @ElementCollection
    @CollectionTable(name = "ADDRESS", joinColumns =
        @JoinColumn(name = "MEMBER_ID")
    )
    //이 상황에서는 저쪽 테이블 만들때의 설정 따로 못해줌(왜냐하면 저쪽 테이블 컬럼이 여러개임)
    private List<Address> addressHistory = new ArrayList<>();

    public Long getId() {
        return id;
    }

    public String getUsername() {
        return username;
    }

    public List<Order> getOrders() {
        return orders;
    }

    public Address getAddress() {
        return address;
    }

    public Set<String> getFavoriteFood() {
        return favoriteFood;
    }

    public List<Address> getAddressHistory() {
        return addressHistory;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public void setOrders(List<Order> orders) {
        this.orders = orders;
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    public void setFavoriteFood(Set<String> favoriteFood) {
        this.favoriteFood = favoriteFood;
    }

    public void setAddressHistory(List<Address> addressHistory) {
        this.addressHistory = addressHistory;
    }
}
