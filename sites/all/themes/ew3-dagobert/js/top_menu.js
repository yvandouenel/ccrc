jQuery(document).ready(function(){
   // get the links of top menu
   var contenus= new Array();
   var positions = new Array();
   jQuery(".menu-name-menu-menu-commodit-haut ul li a").each(function(index){
       contenus[index]=jQuery(this).text();
       var position = jQuery(this).position();
       //alert(position.left+" "+position.top);
       positions[index,0] = position.left;
       positions[index,1] = position.top;
   });
   alert(positions[0,0]);
});
