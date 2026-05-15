function tinhTien(){
    var maHD = document.getElementById("maHD").value.trim();
    var tenKH = document.getElementById("tenKH").value.trim();
    var loaiPhong = document.getElementById("loaiPhong").value.trim().toUpperCase();
    var soNgay = document.getElementById("soNgay").value.trim();

    if(!/^[a-zA-Z]+$/.test(tenKH)){
        alert("Tên không hợp lệ!")
        return;
    }

    if(!/^[ABC]$/.test(loaiPhong)){
        alert("Loại phòng không hợp lệ: A,B,C")
        return;
    }

    var donGia = 0;
    if(loaiPhong === "A"){
        donGia = 300;
    }
    else if(loaiPhong === "B"){
        donGia = 200;
    }
    else if(loaiPhong === "C"){
        donGia = 100;
    }

    if(!/^\d+$/.test(soNgay) || soNgay <=0){
        alert("Số ngày không hợp lệ!")
        return;
    }

    var tien = soNgay*donGia;

    var chietKhau;
    if(soNgay>15){
        chietKhau = tien * 0.1;
        document.getElementById("loaiKH").value = "Thuê dài ngày";
    }else{
        chietKhau = 0;
        document.getElementById("loaiKH").value = "Thuê ngắn ngày";
    }

    document.getElementById("tienTra").value = soNgay*donGia - chietKhau;
}

function huyBo(){
    document.getElementById("maHD").value = "";
    document.getElementById("tenKH").value = "";
    document.getElementById("loaiPhong").value = "";
    document.getElementById("soNgay").value = "";
    document.getElementById("tienTra").value = "";
    document.getElementById("loaiKH").value = "";
}