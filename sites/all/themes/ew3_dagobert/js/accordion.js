jQuery(document).ready(function(){
   
   //Récupère le contenu et les positions
   jQuery(".field-collection-container .field-type-text").each(function(index){
       jQuery(this).attr("id","title_para_"+index);
       jQuery(this).addClass("closed_title");
       jQuery(this).addClass("toggled_title");
       
 
       jQuery(this).click(function(event){
          jQuery("#acc_para_"+index).toggle();

          if(jQuery("#title_para_"+index).hasClass("closed_title")){// test si le paragraphe est fermé...
              jQuery("#title_para_"+index).addClass("opened_title");
              jQuery("#title_para_"+index).removeClass("closed_title");
             
          }else {
              jQuery("#title_para_"+index).addClass("closed_title");
              jQuery("#title_para_"+index).removeClass("opened_title");
          }
       });
      
   });
   jQuery(".field-collection-container .field-type-text-long").each(function(index){
       jQuery(this).hide();
       jQuery(this).attr("id","acc_para_"+index);
   });
   
/*
   //Crée les div et les introduits dans le header
   for(i=0;i<contenus.length;i++){
    var position_y = positions[i]-28;
    jQuery('<div>')                      // Creates the element
    .attr('id','over_menu_'+i) // Sets the attribute spry:region="myDs"
    .attr('class','over_menu')
    .text(contenus[i])       // Sets the inner HTML to {hostname}
    .appendTo('#header')
    .css("left",position_y+"px")
    .css("top","60px")
    .hide();
    //alert(i);
   }

   // rendre les boutons visibles au survol
     jQuery(".menu-name-menu-menu-commodit-haut ul li a").mouseover(function(event){
          var num_icon = 0;
          var reactive_icon = jQuery(event.target).get().toString();

          jQuery(".menu-name-menu-menu-commodit-haut ul li a").each(function(index){
              var this_id_string = jQuery(this).get().toString();
              
              if(this_id_string == reactive_icon) {
                  num_icon = index;
                  //break;
              }
          });
          
          jQuery('#over_menu_'+num_icon).show();
       });
       
   // cacher les boutons au survol
     jQuery(".menu-name-menu-menu-commodit-haut ul li a").mouseout(function(event){
         jQuery('.over_menu').hide();
       });
  */
});
