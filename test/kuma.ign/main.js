enchant();  //お約束！


window.onload = function(){

    var game = new Game(320, 320);
     game.fps = 15;
     game.preload("chara1.png");
     game.rootScene.backgroundColor = "rgba(250, 255, 255, 0.4)";
     game.onload = function(){    //game.startしたときに起動するやつ
        var score = 0; 
        var scoreLabel = new Label();
        scoreLabel.text = 'SCORE:0 ';
        scoreLabel.x = 10;
        scoreLabel.y = 10;
        scoreLabel.addEventListener("enterframe", function() {
         this.text = 'SCORE: '  + score;
       } ) ;
         
       game.rootScene.addChild(scoreLabel);
       
       var maxTime = 300;
       var timerLabel = new Label ();
       timerLabel.x = 100;
       timerLabel.y = 10;
       timerLabel.text = "残り時間：" + maxTime + " s";
       timerLabel.addEventListener("enterframe", function(){
         var progress = parseInt(game.frame / game.fps);
         var time = maxTime - progress;
         this.text = "残り時間：" + time + " s";
         if (time <= 0) {
           var gameOverScene = new Scene();
           gameOverScene.backgroundColor = 'rgba(0, 0, 0, 0.5)';
           game.replaceScene(gameOverScene);
           
           var gameoverLabel = new Label();
           gameoverLabel.width = 320;
           gameoverLabel.y = 120;
           gameoverLabel._element.style.textAlign = "center";
           gameoverLabel.text = "You Dead";
           gameoverLabel.font = "48px serif";
           gameoverLabel.color = "White";
           
           
           gameOverScene.addChild(gameoverLabel);
       }
     } ) ;
     game.rootScene.addChild(timerLabel);
     
       var createBear = function(i){
          var bear = new Sprite(32, 32);
          bear.image = game.assets["chara1.png"];
          bear.x = 0;
          bear.y = 32 * (i + 1);
          bear.frame = 0;
          bear.moveToLeft = function() {
            this.x = -32;
            this.speed = 4 +parseInt(Math.random() * 4);
        }
        bear.moveToLeft() ;
        bear.addEventListener("enterframe",function() {
         bear.x += bear.speed;
         if ( bear.x > 320 ) {
           bear.moveToLeft();
           score -= 2;
         }
         
         if (bear.frame == 1 ) {
           bear.frame = 2;
         }else{
           bear.frame = 1;
         }
         
       } ) ;
       
       
       bear.addEventListener("touchstart", function()  {
         bear.moveToLeft();
         score += 1;
         
       } ) ;
         
       
      game.rootScene.addChild(bear);
    };
    
    for ( var i = 0; i < 9; i++ ) {
        createBear(i);      
    }
  };
    game.start();
};

