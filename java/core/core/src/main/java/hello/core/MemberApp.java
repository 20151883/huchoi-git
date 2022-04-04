package hello.core;

import hello.core.member.*;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class MemberApp {
    public static void main(String[] args) {//psvm -> enter
//        AppConfig appConfig = new AppConfig();
//        MemberService memberService = new MemberServiceImpl();
//        MemberService memberService = appConfig.memberService();
        ApplicationContext applicationContext = new AnnotationConfigApplicationContext(AppConfig.class);
        //ApplicationContext가 spring container이라고 보면 된다. AppConfig클래스에 있는 @bean붙은 녀석들을 모두 인스턴스화해서
        //컨테이너에 집어 넣는다
        MemberService memberService = applicationContext.getBean("memberService", MemberService.class);
        //"name = method이름", 두번째 파라미터는 타입
        //method이름을 부르긴하지만, 실제론 객체를 부르는것
        Member member = new Member("memberA",1L, Grade.VIP);
        memberService.join(member);

        Member findMember = memberService.findMember(1L);
        System.out.println("new member: " + member.getName());
        System.out.println("find member"+ findMember.getName());
    }
}
