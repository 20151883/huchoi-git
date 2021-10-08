const express = require("express");
const morgan = require("morgan");
const cookieParser = require("cookie-parser");
const session = require("express-session");
const dotenv = require("dotenv");
const multer = require("multer");
const fs = require("fs");
const path = require("path");
const { send } = require("process");

const indexRouter = require("./routes/index");
const userRouter = require("./routes/user");

try {
    fs.readdirSync('uploads');
} catch (error) {
    console.log("uploads디렉터리가 없어서 생성하겠습니다");
    fs.mkdirSync("uploads");
}

const upload = multer({
    storage: multer.diskStorage({
        destination(req, file, done) {
            done(null, "uploads/");
        },
        filename(req, file, done) {
            const ext = path.extname(file.originalname);
            done(null, path.basename(file.originalname, ext) + Date.now() + ext);
        },
    }),
    limits: { fileSize: 5 * 1024 * 1024 },
})
dotenv.config();
const app = express();
app.set('port', process.env.PORT || 3000);
app.use(morgan("dev"));
//app.use("/", express.static(path.join(__dirname, "/public")));
app.use((req, res, next) => {
    console.log("여기에 도달하게 됩니다");
    next();
})
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser(process.env.COOKIE_SECRET));
app.use(session({
    resave: false,
    saveUninitialized: false,
    secret: {
        httpOnly: true,
        secure: false,
    },
    name: 'session-cookie',
}))

app.use("/public", indexRouter);
app.use("/user", userRouter);
app.use((req, res, next) => {
    console.log("모든 요청에 대해서 실행됩니다");
    next();
})

app.get('/test.html', (req, res, next) => {
    res.sendFile(path.join(__dirname, "/test.html"));
    console.log(req);
    console.log("get의 첫번째 미들웨어입니다");
    //res.send("hello express");
}, (req, res) => {
    console.log("get의 두번째 미들웨어입니다")
    throw Error("그냥 에러 입니다");
});
app.get("/multipart.html", (req, res, next) => {
    res.sendFile(path.join(__dirname, "/multipart.html"));
});

app.get("/test", (req, res) => {
    res.send("this is test html");
});
/*
app.post("/upload", upload.single("image"), (req, res) => {
    console.log(req.file, req.body);
    res.send("ok");
});
*/

app.post("/upload", upload.array("many"), (req, res) => {
    console.log(req.files, req.body);
    res.send("ok");
})

app.use((req, res, next) => {
    res.status(404).send("404 not founded!");
});
app.use((error, req, res, next) => {
    console.error(error);
    res.status(500).send("500번 에러입니다");
});
app.listen(app.get("port"), () => {
    console.log(app.get("port"), "번 포트에서 대기 중");
});