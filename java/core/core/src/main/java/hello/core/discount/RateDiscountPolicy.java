package hello.core.discount;

import hello.core.member.Grade;
import hello.core.member.Member;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Component;

@Component
@Qualifier("mainDiscountPolicy")
public class RateDiscountPolicy implements DiscountPolicy{

    private final int discountPercent = 10;

    /**
     *
     * @return 할인되는 금액
     */
    @Override
    public int discount(Member member, int price) {

        if (member.getGrade() == Grade.VIP){
            return price * discountPercent / 100;
//            return price * (discountPercent / 100); 이렇게 하면 값이 이상해짐
        }
        else {
            return 0;
        }
    }
}
