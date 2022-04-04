package hellojpa;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.EntityTransaction;
import javax.persistence.Persistence;
import java.util.List;

public class JpaMain {
    public static void main(String[] args) {
        EntityManagerFactory emf = Persistence.createEntityManagerFactory("hello");//unit-name을 인자로 넣어주자
        EntityManager em = emf.createEntityManager();

        EntityTransaction tx = em.getTransaction();
        tx.begin();
        try
        {
            Member member = em.find(Member.class, 1L);
            printMember(member);
            printMemberAndTeam(member);
            tx.commit();
        }catch (Exception e){
            System.out.println("rollback!!");
            tx.rollback();
        }
        finally {
            em.close();
        }//이런 구조로 짜는게 정석구조 -> 그런데 스프링 쓰면은 이 구조 안해도됨. 스프링이 다 알아서 해줌.
        emf.close();
    }

    private static void printMember(Member member) {
        String username = member.getUsername();
        System.out.println("username = " + username);
    }

    private static void printMemberAndTeam(Member member) {
        String username = member.getUsername();
        System.out.println("username = " + username);
        Team team = member.getTeam();
        System.out.println("team = " + team);
    }

}
