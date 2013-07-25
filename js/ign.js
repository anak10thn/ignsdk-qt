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
            ign.exec("notify-send "+opt);
        });
    };
    $.fn.applaunch = function(app) {
        this.click(function(){
            ign.exec(app);
        });
    };
    
    $.fn.download = function(url,path) {
		var xhr = new XMLHttpRequest();
		  xhr.open('GET', url, true);

		  xhr.onprogress = function(evt){
				 if (evt.lengthComputable) {
				   this.val(evt.loaded);
				   this.attr(evt.total);
				   console.log(evt.loaded);
				 }
			   };

		  xhr.responseType = 'arraybuffer';
		  xhr.onreadystatechange = function(e) {
			 if (this.status == 200) {
				var mime = this.getResponseHeader('Content-Type');
				var file = url.split('/');
				var filename = file[file.length - 1];
				console.log(this.response);
				var byteArray = new Uint8Array(this.response);
				var buffer;
						for (var i = 0; i < byteArray.length; i++) {
							buffer += String.fromCharCode(byteArray[i]);
							
						}
				 
				var base64 = window.btoa(buffer);
				 
				ign.saveFile(base64,filename,path);
				 
			 }
		  }

		  xhr.send();
	}

})( jQuery );
