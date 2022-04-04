package jpabook2.jpashop2.repository;

import jpabook2.jpashop2.domain.Member;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Repository;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.PersistenceContext;
import javax.persistence.PersistenceUnit;
import java.util.List;

@Repository
@RequiredArgsConstructor
public class MemberRepository {
//    @PersistenceContext
//    private EntityManager em;

    private final EntityManager em;

    @PersistenceUnit // 엔터티매니저팩토리를 주입받고 싶을때 사용 <- 근데 거의 쓸일이 없을것
    private EntityManagerFactory emf;

    public void save(Member member){
        em.persist(member);
    }

    public Member findOne(Long id){
        Member member = em.find(Member.class, id);
        return member;
    }

    public List<Member> findAll(){
        return em.createQuery("SELECT m from Member m", Member.class).getResultList();
    }

    public List<Member> findByName(String name){
        return em.createQuery("SELECT m from Member m WHERE m.name = :name", Member.class)
                .setParameter("name", name)
                .getResultList();
    }
}
