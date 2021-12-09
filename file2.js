let lf = document.getElementById('libraryForm');
lf.addEventListener('submit', function (e) {
    console.log("it is working ")
    let name = document.getElementById('bookName').value;
    let author = document.getElementById('author').value;
    console.log(name, author);
    let type;
    let fiction = doc.getElementById('fiction');
    let programming = doc.getElementById('programming');
    let cooking = doc.getElementById('cooking');
    if (fiction.checked) {
        type = "Fiction";
    } else if (programming.checked) {
        type = "Computer Programming";
    } else {
        type = "Cooking";
    }
    let tabelBody=document.getElementById('tabelBody'); 
    let ustring=` <tr>
    <th scope="col">${name}</th>
    <th scope="col">${author}</th>
    <th scope="col">${type}</th>
     </tr>`;
     tabelBody.innerHTML+=ustring;
     e.preventDefault();
});


