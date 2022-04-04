package hello.core.beanFind;

import hello.core.discount.DiscountPolicy;
import hello.core.discount.FixDiscountPolicy;
import hello.core.discount.RateDiscountPolicy;
import hello.core.member.MemberRepository;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.NoUniqueBeanDefinitionException;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import java.util.Map;

public class ApplicationContextExtendsFindTest {

    AnnotationConfigApplicationContext ac = new AnnotationConfigApplicationContext(TestConfig.class);


    @Test
    @DisplayName("부모타입으로 조회시 자식객체가 둘이상 존재하면 에러가 발생한다")
    void findBeanByType(){
        Assertions.assertThrows(NoUniqueBeanDefinitionException.class, ()->{ac.getBean(DiscountPolicy.class);});
//        Assertions.assertThrows(NoUniqueBeanDefinitionException.class, ()->{ac.getBean(MemberRepository.class);});
    }

    @Test
    @DisplayName("부모타입으로 조회시 자식객체가 둘이상 존재하면 이름을 지정하면 된다.")
    void findBeanByTypeAndName(){
        Object result = ac.getBean("discountPolicy1", DiscountPolicy.class);
        org.assertj.core.api.Assertions.assertThat(result).isInstanceOf(RateDiscountPolicy.class);
    }

    @Test
    @DisplayName("부모타입으로 조회시 자식객체가 둘이상 존재하면 특정하위타입으로 하면된다.")//안좋은 방법인듯
    void findBeanBySpecificType(){
        Object result = ac.getBean(RateDiscountPolicy.class);
        org.assertj.core.api.Assertions.assertThat(result).isInstanceOf(RateDiscountPolicy.class);
    }

    @Test
    @DisplayName("타입으로 '조회'시 같은 타입이 둘이상 있다면 그때는 이름을 넣어주자")//스프링 빈 만들때에는 문제가 안되다가...
    void findAllBeanByType(){//실제로 테스트시에 출력물을 남기는건 좋지 않은거..
        Map<String, DiscountPolicy> beansOfType = ac.getBeansOfType(DiscountPolicy.class);
        for (String s : beansOfType.keySet()) {
            System.out.println("key = " + s + "value: " + beansOfType.get(s));
        }
//        Assertions.assertThrows(NoUniqueBeanDefinitionException.class, ()->{ac.getBean(MemberRepository.class);});
    }

    @Test
    @DisplayName("타입으로 '조회'시 같은 타입이 둘이상 있다면 그때는 이름을 넣어주자")//스프링 빈 만들때에는 문제가 안되다가...
    void findAllBeanByObject(){//실제로 테스트시에 출력물을 남기는건 좋지 않은거..
        Map<String, Object> beansOfType = ac.getBeansOfType(Object.class);
        for (String s : beansOfType.keySet()) {
            System.out.println("key = " + s + "value: " + beansOfType.get(s));
        }
//        Assertions.assertThrows(NoUniqueBeanDefinitionException.class, ()->{ac.getBean(MemberRepository.class);});
    }


    @Configuration
    static class TestConfig{
        @Bean
        public DiscountPolicy discountPolicy1(){
            return new RateDiscountPolicy();
        }

        @Bean
        public DiscountPolicy discountPolicy2(){
            return new FixDiscountPolicy();
        }
    }
}
