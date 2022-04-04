package jpabook.jpashop;

import org.assertj.core.api.Assertions;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.annotation.Rollback;
import org.springframework.test.context.junit4.SpringRunner;
import org.springframework.transaction.annotation.Transactional;

import static org.assertj.core.api.Assertions.*;
import static org.junit.Assert.*;

@RunWith(SpringRunner.class)//junit에게 스프링으로 돌릴거라고 알려줌
@SpringBootTest//스프링 부트로 돌려야 하기 때문
public class MemberRepositoryTest {
    @Autowired MemberRepository memberRepository;

    @Test
    @Transactional
    @Rollback(false)
    public void testMember() throws Exception{
        //given
        Member member = new Member();
        member.setUsername("memberA");
        //when
        Long id = memberRepository.save(member);
        Member member1 = memberRepository.find(id);

        //then
        assertThat(member).isEqualTo(member1);
        assertThat(member).isSameAs(member1);
    }
}