$(document).ready(function() {

    //Activate materialize elements
    $('.dropdown-button').dropdown();
    $('.modal').modal();

    var fieldSize = 0;
    var traps = 0;
    var wumpus = 0;

    $('#randomValuesBtn').click(function() {

        //Calculate the field size, number of traps and wumpus randomly
        fieldSize = Math.floor((Math.random() * 12) + 4); //Adjust the % value to the the upper bounce
        traps = Math.floor((Math.random() * (Math.pow(fieldSize, 2) / 4)) + 1);
        wumpus = Math.floor((Math.random() * fieldSize) + 1);

        $('#playgroundSize').val(fieldSize);
        $('#trapNumbers').val(traps);
        $('#wumpusNumbers').val(wumpus);
        $('#arrowAgent').prop('checked', (fieldSize % 2 === 0));

        Materialize.updateTextFields();

    });

    $('#settingsCancel').click(function() {

        $('#newWorldModal').modal('close');

    });


    $('#settingsOk').click(function() {

        if($('#playgroundSize').val() && $('#trapNumbers').val() && $('#wumpusNumbers').val()) {

            $('#arrow').text('Arrow: ' + (fieldSize % 2 === 0));
            $('#wumpus').text('Wumpus: ' + wumpus);
            $('#traps').text('Traps: ' + traps);
            $('#size').text('Size: ' + fieldSize);

            $('#newWorldModal').modal('close');

        }
    });
});

