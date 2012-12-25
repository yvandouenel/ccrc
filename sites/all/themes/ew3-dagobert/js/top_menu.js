jQuery(document).ready(function(){
   // get the links of top menu
   var contenus= new Array();
   var positions = new Array();

   //Récupère le contenu et les positions
   jQuery(".menu-name-menu-menu-commodit-haut ul li a").each(function(index){
       contenus[index]=jQuery(this).text();
       var position = jQuery(this).position();
       //alert(position.left+" "+position.top);
       positions[index,0] = position.left;
       positions[index,1] = position.top;
   });

   //Crée les div et les introduits dans le header
   for(i=0;i<contenus.length;i++){
    jQuery('<div>')                      // Creates the element
    .attr('id','over_menu_'+i) // Sets the attribute spry:region="myDs"
    .attr('class','over_menu')
    .text(contenus[i])       // Sets the inner HTML to {hostname}
    .appendTo('#header')
    .hide();
    //alert(i);
   }

   // rendre les boutons visibles au survol
     jQuery(".menu-name-menu-menu-commodit-haut ul li a").mouseover(function(event){
         jQuery('#over_menu_0').show();
       });
       
   // cacher les boutons au survol
     jQuery(".menu-name-menu-menu-commodit-haut ul li a").mouseout(function(event){
         jQuery('#over_menu_0').hide();
       });
  
});
