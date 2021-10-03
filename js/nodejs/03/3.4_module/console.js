const string = "abc";
const number = 3;
const boolean = true;
const obj = {
    outside: {
        inside: {
            key: "value",
        },
    },
};
console.time("전체시간");
console.log("평범한 로그입니다 쉼표로 구분해 여러값을 찍을수 있습니다");
console.log(string, number, boolean);
console.error("에러메시지는 error메서드에 담아주세요");

console.table([{ name: "zero", birth: "two" }, { name: "one", birth: "three" }]);

console.dir(obj, { colors: true, depth: 3 });
console.dir(obj, { colors: false, depth: 1 });

console.time("시간측정1");
for (let i = 0; i < 1000000; i++) {}
console.timeEnd("시간측정1");

function b() {
    console.trace("에러 위치 추적");
}

function a() {
    b();
}
a();

console.timeEnd("전체시간");