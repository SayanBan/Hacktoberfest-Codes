<!DOCTYPE html>
<html>
<body>

<p>The typeof operator returns the type of a variable or an expression.</p>

<p id="demo"></p>

<script>
document.getElementById("demo").innerHTML = 
typeof "" + "<br>" +
typeof "John" + "<br>" + 
typeof "John Doe" + "<br>" +
typeof 0 + "<br>" +
typeof 314 + "<br>" +
typeof 3.14 + "<br>" +
typeof (3.14);
</script>
</body>
</html>
