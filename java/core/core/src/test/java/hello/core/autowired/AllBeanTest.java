package hello.core.autowired;

import hello.core.AutoAppConfig;
import hello.core.discount.DiscountPolicy;
import hello.core.member.Grade;
import hello.core.member.Member;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.core.AutoConfigureCache;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

import java.util.List;
import java.util.Map;

import static org.assertj.core.api.Assertions.*;

public class AllBeanTest {

    @Test
    void findAllBean(){
        AnnotationConfigApplicationContext ac = new AnnotationConfigApplicationContext(AutoAppConfig.class, DiscountService.class);
        DiscountService discountService = ac.getBean(DiscountService.class);
        Member member = new Member("userA", 1L, Grade.VIP);
        int howMuch = discountService.discount(member, 10000, "fixDiscountPolicy");
        assertThat(discountService).isInstanceOf(DiscountService.class);
        assertThat(howMuch).isEqualTo(1000);

        howMuch = discountService.discount(member, 20000, "rateDiscountPolicy");
        assertThat(discountService).isInstanceOf(DiscountService.class);
        assertThat(howMuch).isEqualTo(2000);
    }

    static class DiscountService{
        private final Map<String, DiscountPolicy> policyMap;
        private final List<DiscountPolicy> discountPolicyList;

        //@Autowired 안붙여도 됨(생성자가 하나뿐이기에)
        public DiscountService(Map<String, DiscountPolicy> policyMap, List<DiscountPolicy> discountPolicyList) {
            this.policyMap = policyMap;
            this.discountPolicyList = discountPolicyList;
            System.out.println("policyMap = " + policyMap);
            System.out.println("discountPolicyList = " + discountPolicyList);

        }

        public int discount(Member member, int i, String str) {
            DiscountPolicy discountPolicy = this.policyMap.get(str);
            return discountPolicy.discount(member, i);
        }
    }
}
