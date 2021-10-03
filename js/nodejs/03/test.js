var candyMachine = {
	status : {name:"node", count:5},
	getCandy(){
		this.status.count--;
		return this.status.count;
	},
};

const {getCandy, status:{count}, status} = candyMachine;
let bind_test = getCandy.bind(candyMachine);
console.log(bind_test());

console.log(count);
console.log(status.count);
