<!DOCTYPE html>
<html>
<body>

<p>Click "Try it" to call a function with arguments</p>

<button onclick="myFunction('Harry Potter','Wizard')">Try it</button>

<p id="demo"></p>

<script>
function myFunction(name,job) {
  document.getElementById("demo").innerHTML = "Welcome " + name + ", the " + job + ".";
}
</script>

</body>
</html>
