function generateQrCode() {
    const qrText = document.getElementById("qrText").value;
    const generatedQrCode = document.getElementById("generatedQrCode");
  
    generatedQrCode.innerHTML = "";
    const qrCode = new QRCode(generatedQrCode, {
      text: qrText,
      width: 256,
      height: 256,
      colorDark: "#000000",
      colorLight: "#ffffff",
      correctLevel: QRCode.CorrectLevel.H
    });
  }
  
  