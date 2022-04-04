package jpabook2.jpashop2;

import org.springframework.stereotype.Repository;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

@Repository
public class MemberSRepository {
    @PersistenceContext
    EntityManager em;

    public Long save(MemberS memberS) {
        em.persist(memberS);
        return memberS.getId();
    }
    public MemberS find(Long id) {
        return em.find(MemberS.class, id);
    }
}
