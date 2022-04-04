package hello.core.scope;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Scope;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import static org.assertj.core.api.Assertions.*;

public class PrototypeTest {

    @Test
    public void prototypeTest(){
        AnnotationConfigApplicationContext ac = new AnnotationConfigApplicationContext(PrototypeBean.class);
        System.out.println("find prototype1");
        PrototypeBean prototypeBean = ac.getBean(PrototypeBean.class);//조회하기 직전에 객체가 생성됨
        System.out.println("find prototype2");
        PrototypeBean prototypeBean1 = ac.getBean(PrototypeBean.class);//조회하기 직전에 객체가 생성됨
        assertThat(prototypeBean).isNotSameAs(prototypeBean1);
        //@destroy 호출이 안되었음 -> 개발자가 호출할 방법이 아예 없는건가?? -> 그냥 메서드 호출하면 됨.... 어노테이션 붙인다고 기능이 축소가 되는건 절대 아님
        prototypeBean.destroy();
        prototypeBean1.destroy();
    }

    @Scope("prototype")
    static class PrototypeBean{
        @PostConstruct
        void init(){
            System.out.println("PrototypeBean.init");
        }

        @PreDestroy
        void destroy(){
            System.out.println("PrototypeBean.destroy");
        }

    }
}
