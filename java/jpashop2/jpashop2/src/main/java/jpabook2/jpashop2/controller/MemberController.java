package jpabook2.jpashop2.controller;

import jpabook2.jpashop2.domain.Address;
import jpabook2.jpashop2.domain.Member;
import jpabook2.jpashop2.service.MemberService;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;

import javax.validation.Valid;
import java.util.List;

@Controller
@RequiredArgsConstructor
public class MemberController {
    private final MemberService memberService;

    @GetMapping("/members/new")
    public String form(Model model){
        model.addAttribute("memberForm", new MemberForm());//memberForm객체를 뷰에 넘긴것. 뷰는 이 객체를 쓸수가 있다. getter, setter, 메서드 사용 가능하다는 얘기!!
        return "members/createMemberForm";
    }

    @PostMapping("/members/new")//아래에 Member를 안주고, MemberForm을 만들어서 넣어준이유 : DTO(정보저장의 목적보다는...유효성검증의 목적이 더 큼)
    public String create(@Valid MemberForm memberForm, BindingResult result){//@Valid 붙이면 스프링에서 유효성 점검을 해준다. MemberForm클래스안에 있는 @NotEmpty같은것들을 보고..
        //위에서 유효성점검에서 실패하면 원래는 그냥 아래 함수본문 실행이 안됨. But BindingResult를 두면 이 result에 뭔가 값이 들어오고, 아래 본문 실행이 됨
        //result에 들어오는 값은 첫번째 인자인 memberForm내용 + 에러와 관련된 내용
        if (result.hasErrors())
            return "members/createMemberForm";//신기하게도 NotEmpty에 적어놓았던 메시지가 html에 표시가 됨...<-위에서 설명했다시피 result에 에러내용이 들어가 있기에..
        Address address = new Address(memberForm.getCity(), memberForm.getStreet(), memberForm.getZipcode());
        Member member = new Member();
        member.setName(memberForm.getName());
        member.setAddress(address);
        memberService.join(member);
        return "redirect:/";
    }

    @GetMapping("/members")
    public String members(Model model){
        List<Member> members = memberService.findMembers();
        model.addAttribute("members", members);
        return "members/memberList";
    }
}
