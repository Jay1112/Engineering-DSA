function printAllSubsequences(str){
  
  function findAllSubsequences(str, index, current){
    if(str.length === index){
      console.log(current);
      return;
    }
    findAllSubsequences(str, index + 1, current);
    findAllSubsequences(str, index + 1, current + str[index]);
  }
  
  findAllSubsequences(str, 0, "");
}


const str = "abc";
printAllSubsequences(str);