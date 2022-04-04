package jpabook2.jpashop2.service;

import jpabook2.jpashop2.domain.Member;
import jpabook2.jpashop2.repository.MemberRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
@Transactional//데이터를 저장하기위해선 트랜잭션이 꼭 필요하다. 그래서 이 어노테이션 사용. 일단 public 메서드는 자동으로 트랜잭션단위에 들어가게 됨
@RequiredArgsConstructor
public class MemberService {
    private final MemberRepository memberRepository;

    //회원 가입
    @Transactional
    public Long join(Member member){
        validateDuplicatedMember(member);
        this.memberRepository.save(member);
        return member.getId();
    }

//    @Transactional(readOnly = true)//readOnly = true 주면 실수로 데이터변경도 예방 + jpa의 성능이 증가(dirty check같은거 안하니까)
    public List<Member> findMembers(){
        return memberRepository.findAll();
    }

//    @Transactional(readOnly = true)
    public Member findOne(Long memberId){
        return memberRepository.findOne(memberId);
    }

    private void validateDuplicatedMember(Member member) {
        //예외를 던질 예정
        List<Member> result = this.memberRepository.findByName(member.getName());
        if (!result.isEmpty()){
            throw new IllegalStateException("이미 존재하는 회원입니다");
        }
    }


}
