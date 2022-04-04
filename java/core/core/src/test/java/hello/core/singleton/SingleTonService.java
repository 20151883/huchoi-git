package hello.core.singleton;

public class SingleTonService {
    private static final SingleTonService instance = new SingleTonService();// <- *****

    public static SingleTonService getInstace(){
        return instance;
    }

    private SingleTonService(){}//더이상 외부에서는 SingletoneService 객체를 생성할수가 없다.(새로운 객체생성을 아예 막음)

    public void logic(){
        System.out.println("싱글톤 객체 로직 함수 호출");
    }
}
