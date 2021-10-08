const express = require("express");
const path = require("path");

const app = express();
app.set('port', process.env.PORT || 3000);

app.use((req, res, next) => {
    console.log("모든 요청에 대해서 실행됩니다");
    next();
})

app.get('/', (req, res, next) => {
    res.sendFile(path.join(__dirname, "/index.html"));
    console.log("get의 첫번째 미들웨어입니다");
    next();
    //res.send("hello express");
}, (req, res) => {
    console.log("get의 두번째 미들웨어입니다")
    throw Error("그냥 에러 입니다");
});

app.get("/test", (req, res) => {
    res.send("this is test html");
})
app.use((error, req, res, next) => {
    console.error(error);
    res.status(500).send("500번 에러입니다");
})
app.listen(app.get("port"), () => {
    console.log(app.get("port"), "번 포트에서 대기 중");
});