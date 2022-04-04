package hello.core.lifecycle;

import org.junit.jupiter.api.Test;
import org.springframework.context.ConfigurableApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import java.lang.annotation.Annotation;

public class BeanLifeCycleTest {
    @Test
    public void lifeCycleTest(){
        ConfigurableApplicationContext ac = new AnnotationConfigApplicationContext(config.class);//좌항의 클래스가 처음보는거임
        NetworkClient networkClient = ac.getBean(NetworkClient.class);
        ac.close();//ConfigurableApplicationContext에 close 메서드가 존재함
    }

    @Configuration
    static class config{
        @Bean //(initMethod = "init", destroyMethod = "close")
        public NetworkClient networkClient(){
            NetworkClient networkClient = new NetworkClient();
            networkClient.setUrl("https://testUrl");
            return networkClient;
        }
    }
}
