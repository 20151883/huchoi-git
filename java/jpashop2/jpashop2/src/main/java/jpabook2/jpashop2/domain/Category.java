package jpabook2.jpashop2.domain;

import jpabook2.jpashop2.domain.item.Item;
import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

@Entity
@Getter @Setter
public class Category {
    @Id @GeneratedValue
    @Column(name = "category_id")
    private Long id;

    private String name;

    @ManyToMany
    @JoinTable(name = "category_item",
        joinColumns = @JoinColumn(name = "category_id"),
            inverseJoinColumns = @JoinColumn(name = "item_id")
    )//다대다는 중간에 테이블이 만들어져야만 하기에...
    private List<Item> items = new ArrayList<>();

    //셀프로 양방향 연관관계
    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "parent_id")
    private Category parent;

    @OneToMany(mappedBy = "parent")
    private List<Category> child = new ArrayList<>();

    //==연관관계 편의 메서드==//

    public void addChildCategory(Category category){
        this.child.add(category);
        category.setParent(this);
    }

//    public void setParentCatecory(Category category){
//        this.parent = category;
//        parent.getChild().add(category);
//    } 이 메서드는 왜 안만드시는지...? 만들필요가 없나..?
}
