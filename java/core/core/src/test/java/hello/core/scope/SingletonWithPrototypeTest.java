package hello.core.scope;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.ObjectProvider;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Scope;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

public class SingletonWithPrototypeTest {

    @Test
    void singletonWithPrototypeTest(){
        AnnotationConfigApplicationContext ac = new AnnotationConfigApplicationContext(PrototypeBean.class);
        PrototypeBean prototypeBean1 = ac.getBean(PrototypeBean.class);
        prototypeBean1.addCount();
        Assertions.assertThat(prototypeBean1.getCount()).isEqualTo(1);

        PrototypeBean prototypeBean2 = ac.getBean(PrototypeBean.class);
        prototypeBean2.addCount();
        Assertions.assertThat(prototypeBean2.getCount()).isEqualTo(1);
    }

    @Test
    public void singtonTest(){
        AnnotationConfigApplicationContext ac = new AnnotationConfigApplicationContext(ClientBean.class, PrototypeBean.class);//PrototypeBean도 등록해줘야함!! 중요
        ClientBean clientBean1 = ac.getBean(ClientBean.class);
        System.out.println("clientBean1 " + clientBean1.logic());
        ClientBean clientBean2 = ac.getBean(ClientBean.class);
        System.out.println("clientBean2 " + clientBean2.logic());
    }

    @Scope("singleton")
    static class ClientBean{
        //private final PrototypeBean prototypeBean;
//        @Autowired//기본적으로 ClientBean이 스프링빈으로 등록될때 @Autowired가 쓸모가 있겠다. 생성자 하나니까 @Autowired 생략해도 됨
//        public ClientBean(PrototypeBean prototypeBean) {
//            this.prototypeBean = prototypeBean;
//        }

        @Autowired
        private ObjectProvider<PrototypeBean> prototypeBeanProvider;

        public int logic(){
            PrototypeBean prototypeBean1 = prototypeBeanProvider.getObject();
            prototypeBean1.addCount();
            return prototypeBean1.getCount();
        }
    }
    @Scope("prototype")
    static class PrototypeBean{
        private int count = 0;

        public void addCount(){
            this.count++;
        }
        public int getCount(){
            return count;
        }

        @PostConstruct
        public void init(){
            System.out.println("PrototypeBean.init" + this);
        }

        @PreDestroy
        public void destroy(){
            System.out.println("PrototypeBean.destroy");
        }
    }
}
