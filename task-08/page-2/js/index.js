function button1(){
    localStorage.setItem("task", "button1");
    alert("Successfully stored on Local Storage.");

}

function button2(){
    var currenttime = new Date();
    alert(currenttime);
}

function button3() {
    document.body.style.background = "black";
}

function button4(){
    document.location.reload(true);
}

function button5(){
    window.open();
}

function button6(){
    console.log("I did it");
}
