(function( $ ){

  $.fn.quit = function() {
      this.click(function(){
          ign.quit();
      });
  };
    $.fn.fullscreen = function(option) {
        this.click(function(){
            if(option){
                ign.getFullScreen(true);
            }
            else{
                ign.getFullScreen(false);
            }
        });
    };
    $.fn.notifySend = function(options) {
        var set = $.extend( {
              'icon': 'none',
              'title': 'none',
              'msg' : 'none',
              'time': '2000'
            }, options);
        var opt = "";
        if(set.icon != 'none'){
            opt += " -i "+set.icon;
        }
        if(set.title != 'none'){
            opt += " \""+set.title+"\" ";
        }
        if(set.msg != 'none'){
            opt += " \""+set.msg+"\" ";
        }
        if(set.time != '2000'){
            opt += " -t "+set.time;
        }
        this.click(function(){
            ign.cliOut("notify-send "+opt);
        });
    };
    $.fn.applaunch = function(app) {
        this.click(function(){
            ign.cliOut("xdg-open /usr/share/applications/"+app+".desktop");
        });
    };

})( jQuery );
