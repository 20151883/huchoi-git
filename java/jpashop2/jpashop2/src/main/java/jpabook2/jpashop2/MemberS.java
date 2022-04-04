package jpabook2.jpashop2;

import lombok.Getter;
import lombok.Setter;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.IdClass;

@Entity
@Getter @Setter
public class MemberS {
    @Id
    @GeneratedValue
    private Long id;

    private String username;

}
