var statValue = 0;

function swapPicture() {
	document.getElementById('sink').style.display = "none"
};

function swapBG() {
	if (statValue == 0) {
		document.getElementById('report1').style.display = "none"
		document.getElementById('report2').style.display = "block"
		document.getElementById('report3').style.display = "none"
		document.getElementById('report4').style.display = "block"
		document.getElementById('report5').style.display = "none"
		document.getElementById('bg').src = "background1.png";
		statValue = 1;		
	} else {
		document.getElementById('report1').style.display = "block"
		document.getElementById('report2').style.display = "none"
		document.getElementById('report3').style.display = "block"
		document.getElementById('report4').style.display = "none"
		document.getElementById('report5').style.display = "block"
		document.getElementById('bg').src = "background.png";
		statValue = 0;
	}

}