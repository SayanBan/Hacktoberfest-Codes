function rotate(str, dir){

    var arr = dir.split("");
     function left(str, d){
       var ans = str.substr(d) + str.substr(0, d);
       return ans;
     }
     function right(str, d){
         var l = str.length;
         return left(str, l - d);
     }
     var str1 = "";
     var first = str;
     for(var i = 0; i<dir.length; i = i+4){
         
         if(arr[i] == 'L'){
             first = left(first, parseInt(arr[i+2]));
         }
         else
         first = right(first, parseInt(arr[i+2]));

         str1 += first.charAt(0);
     }
     var l1 = str1.length;
     var arra = [];
     for(var i = 0; i<str.length-l1; i++){
         arra.push(str.slice(i, i+l1));
     }
     var l2 = arra.length;
     var str2 = str1.split('').sort().join('');
     var flag = 0;
     for(var i = 0; i<l2; i++){
        arra[i] = arra[i].split('').sort().join('');
        if(arra[i] === str2){
        flag = 1;
        break;
        }
     }
     if(flag == 1)
     return "YES";
     else
      return "NO";
}
module.exports = rotate;
