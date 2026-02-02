let example = `
3
3
10 7 6
3
3 5 9
5
1 1 3 1 2
`
let data = example.trim();

data = data.split('\n');
data.shift();
for (let i = 0; i < data.length; i+=2) {
    let isShare = data[i+1].split(' ').map(Number);
    let isMaxNum = Math.max.apply(null,isShare);
    console.log(isMaxNum, isShare)
}
