package hello.core.singleton;


import hello.core.AppConfig;
import hello.core.member.MemberService;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class SingletonTest {
    @Test
    @DisplayName("스프링없는 순수한 DI컨테이너")
    void pureContainer(){
        AppConfig appConfig = new AppConfig();
        MemberService memberService1 = appConfig.memberService();
        MemberService memberService2 = appConfig.memberService();

        System.out.println("memberservice1 = "+ memberService1);
        System.out.println("memberservice2 = "+ memberService2);

        Assertions.assertThat(memberService1).isNotSameAs(memberService2);
    }

    @Test
    @DisplayName("싱글톤 패턴을 적용한 객체 사용")
    void singletonServiceTest(){
//        SingleTonService singletonService = new SingleTonService();
        SingleTonService instace = SingleTonService.getInstace();
        SingleTonService instace2 = SingleTonService.getInstace();

        System.out.println("instance1 = "+ instace);
        System.out.println("instance2 = "+ instace2);

        Assertions.assertThat(instace).isSameAs(instace2);//isSameAs는 "동일한 인스턴스인지"를 비교함
    }

    @Test
    @DisplayName("스프링 컨테이너와 싱글톤")
    void springContainer(){
        ApplicationContext ac = new AnnotationConfigApplicationContext(AppConfig.class);
//        AppConfig appConfig = new AppConfig();
        MemberService memberService1 = ac.getBean("memberService", MemberService.class);
        MemberService memberService2 = ac.getBean("memberService", MemberService.class);

        System.out.println("memberservice1 = "+ memberService1);
        System.out.println("memberservice2 = "+ memberService2);

        Assertions.assertThat(memberService1).isSameAs(memberService2);
    }
}
