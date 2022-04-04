package hellojpa;

import javax.persistence.Entity;

@Entity //<- 이거 없어도 되나? 테이블 매핑을 위한 거니까 필수임
public class Album extends Item{
    private String artist;
}
