package hello.core.autowired;

import hello.core.member.Member;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.lang.Nullable;

import java.util.Optional;

public class AutoWiredTest {

    @Test
    void AutoWiredTest(){
        ApplicationContext ac = new AnnotationConfigApplicationContext(TestBean.class);//이렇게 해주면 스프링빈으로 등록이 됨
     }

    static class TestBean{
        @Autowired(required = false)
        public void setNoBean1(Member member){
            System.out.println("TestBean.setNoBean1");
        }

        @Autowired
        public void setNoBean2(@Nullable Member member){
            System.out.println("TestBean.setNoBean2" + member);
        }

        @Autowired(required = false)
        public void setNoBean3(Optional<Member> member){
            System.out.println("TestBean.setNoBean3" + member);
        }
    }
}
