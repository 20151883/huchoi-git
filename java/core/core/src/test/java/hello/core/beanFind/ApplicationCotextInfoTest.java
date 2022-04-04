package hello.core.beanFind;

import hello.core.AppConfig;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class ApplicationCotextInfoTest {
    AnnotationConfigApplicationContext ac = new AnnotationConfigApplicationContext(AppConfig.class);

    @Test
    @DisplayName("스프링 빈 목록 출력해보기")
    void findBean(){
        String[] beanDefinitionNames = ac.getBeanDefinitionNames();
        //iter + enter(혹은 iter + tab)하면 '향상된 for문'이 자동으로 생성됨!
        for (String beanDefinitionName : beanDefinitionNames){
            Object bean = ac.getBean(beanDefinitionName);
            System.out.println("name= " + beanDefinitionName + " object= " + bean);
        }
    }
}
