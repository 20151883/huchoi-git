package hello.core.lifecycle;

import org.springframework.beans.factory.DisposableBean;
import org.springframework.beans.factory.InitializingBean;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

public class NetworkClient {
    private String url;

    public NetworkClient() {
        System.out.println("생성자호출 url = " + url);
//        connect();
//        call("초기화할 메시지");
    }

    public void setUrl(String url) {
        this.url = url;
    }

    //서비스 시작시 호출
    public void connect(){
        System.out.println("connect " + url);
    }

    public void call(String msg){
        System.out.println("call : " + url + "msg  : " + msg);
    }

    //서비스 종료시 호출
    public void disconnect(){
        System.out.println("close " + url);
    }

    @PreDestroy
    public void close() throws Exception {
        System.out.println("network close");
        disconnect();
    }

    @PostConstruct
    public void init() throws Exception {
        System.out.println("network initialize");
        connect();
        call("초기화할 메시지");
    }
}
