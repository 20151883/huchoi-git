package jpabook.jpashop.domain;

import javax.persistence.Embeddable;
import java.util.Objects;

@Embeddable
public class Address {
    public Address() {

    }

    public Address(String city, String street, String zipcode) {
        this.city = city;
        this.street = street;
        this.zipcode = zipcode;
    }
    private String city;
    private String street;
    private String zipcode;

    public String getCity() {
        return city;
    }

    public String getStreet() {
        return street;
    }

    public String getZipcode() {
        return zipcode;
    }

    private void setCity(String city) {
        this.city = city;
    }

    private void setStreet(String street) {
        this.street = street;
    }

    private void setZipcode(String zipcode) {
        this.zipcode = zipcode;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Address address = (Address) o;
        return Objects.equals(city, address.city) && Objects.equals(street, address.street) && Objects.equals(zipcode, address.zipcode);
    }//여기서 getter를 호출하여 비교를 하는데, 프록시를 인자르 넣어줘도 비교가 잘 되겠다
    //음.. getter가 아닌 다른 걸 사용해서 비교할수 있나..?
    //아무튼... 뭔가를 할때 무조건 메서드를 사용해서 하자. 그게 JPA할때 안전하다고 얘기하심.(객체지향적이기도 하고..)

    @Override
    public int hashCode() {
        return Objects.hash(city, street, zipcode);
    }
}
