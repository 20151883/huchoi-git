package jpabook2.jpashop2.service;

import jpabook2.jpashop2.domain.Member;
import jpabook2.jpashop2.repository.MemberRepository;
import org.junit.jupiter.api.Assertions;
import org.junit.Test;//<-아까는 왜 org.junit.jupiter.test? 이런거 import 됐을까..?
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;
import org.springframework.transaction.annotation.Transactional;

import static org.junit.jupiter.api.Assertions.*;


@RunWith(SpringRunner.class)//junit실행할때 스프링이랑 같이 실행하고자 할때 적어주자
@SpringBootTest//이거 없으면 @Autowirded 잘 안되겠다.
@Transactional//데이터를 변경할것이기 때문....? 왜냐하면 스프링에서 트랜잭션은 디폴트가 롤백을 해버림 커밋을 안하고..
//롤백을 안하고 커밋을 하고 싶다면 해당 메서드에서 Rollback(false) // 롤백은 정확히 말하면 영속성 컨텍스트에서 플러시를 안해버리는것
//초반에는 db에 들어간 내용을 보고 판단하는것도 좋기때문에, Rollback(false)로 하고 해보는걸 추천!
public class MemberServiceTest {

    @Autowired MemberService memberService;
    @Autowired MemberRepository memberRepository;

    @Test
    public void 회원가입() throws Exception{
        //given
        Member member = new Member();
        member.setName("memberA");
        //when
        Long id = this.memberService.join(member);
        //then
        assertEquals(member, memberRepository.findOne(id));
    }

    @Test
    public void 중복회원예외() throws Exception{
        //given
        Member memberA = new Member();
        memberA.setName("kim");
        Member memberB = new Member();
        memberB.setName("kim");
        //when
        memberService.join(memberA);
        try {
            memberService.join(memberB);
        }
        catch (IllegalStateException e){
            return ;
        }
        //then
        fail("예외가 발생한다");//**이 줄에 도달하게 되면 실패로 간주하는것!!**
    }
}