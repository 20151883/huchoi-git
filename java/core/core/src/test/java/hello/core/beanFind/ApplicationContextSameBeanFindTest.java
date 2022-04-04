package hello.core.beanFind;

import hello.core.AppConfig;
import hello.core.member.MemberRepository;
import hello.core.member.MemberService;
import hello.core.member.MemberServiceImpl;
import hello.core.member.MemoryMemberRepository;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.NoUniqueBeanDefinitionException;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import java.util.Map;

public class ApplicationContextSameBeanFindTest {

//    AnnotationConfigApplicationContext ac = new AnnotationConfigApplicationContext(AppConfig.class);
    AnnotationConfigApplicationContext ac = new AnnotationConfigApplicationContext(SameBeanConfig.class);
    @Test
    @DisplayName("타입으로 '조회'시 같은 타입이 둘이상 있다면 중복에러가 발생한다")//스프링 빈 만들때에는 문제가 안되다가...
    void findBeanByTypeDuplicate(){
//        MemberRepository memberRepository = ac.getBean(MemberRepository.class);
//        Assertions.assertThat(memberRepository).isInstanceOf(MemberServiceImpl.class);
        Assertions.assertThrows(NoUniqueBeanDefinitionException.class, ()->{ac.getBean(MemberRepository.class);});
    }

    @Test
    @DisplayName("타입으로 '조회'시 같은 타입이 둘이상 있다면 그때는 이름을 넣어주자")//스프링 빈 만들때에는 문제가 안되다가...
    void findBeanByTypeAndName(){
        MemberRepository memberRepository = ac.getBean("memberRepository1", MemberRepository.class);
        org.assertj.core.api.Assertions.assertThat(memberRepository).isInstanceOf(MemberRepository.class);
//        Assertions.assertThrows(NoUniqueBeanDefinitionException.class, ()->{ac.getBean(MemberRepository.class);});
    }

    @Test
    @DisplayName("타입으로 '조회'시 같은 타입이 둘이상 있다면 그때는 이름을 넣어주자")//스프링 빈 만들때에는 문제가 안되다가...
    void findAllBeanByType(){
        Map<String, MemberRepository> beansOfType = ac.getBeansOfType(MemberRepository.class);
        for (String s : beansOfType.keySet()) {
            System.out.println("key = " + s + "value: " + beansOfType.get(s));
        }
//        Assertions.assertThrows(NoUniqueBeanDefinitionException.class, ()->{ac.getBean(MemberRepository.class);});
    }

    //@Configuration
    static class SameBeanConfig{
        @Bean
        public MemberRepository memberRepository1(){
            return new MemoryMemberRepository();
        }

        @Bean
        public MemberRepository memberRepository2(){
            return new MemoryMemberRepository();
        }
        //위에는 실무에서도 나올수 있는 상황임. 같은 레파지토리라도 생성자가 인자를 받는다면 다른 인자를 넣어줄수도 있기떄문
        //일단 스프링 빈 만들때 동일한 클래스의 인스턴스를 여러개 만드는건 문제가 안된다.
        //메서드의 이름과 인스턴스의 주소값이 pk이지, 클래스는 pk는 아닌느낌.. 그래서 삽입은 잘 되는듯..
        //그런데 조회하려고 할때, pk가 아닌 컬럼으로 조회하려고 하면 일단 허용은 되는데 중복이 발생하면 그땐 에러를 띄우게 설계
    }
}

