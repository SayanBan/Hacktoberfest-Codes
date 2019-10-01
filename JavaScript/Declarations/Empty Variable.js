<!DOCTYPE html>
<html>
<body>

<h2>JavaScript</h2>

<p>An empty string has both a legal value and a type:</p>

<p id="demo"></p>

<script>
var car = "";
document.getElementById("demo").innerHTML =
"The value is: " +
car + "<br>" +
"The type is: " + typeof car;
</script>

</body>
</html>
