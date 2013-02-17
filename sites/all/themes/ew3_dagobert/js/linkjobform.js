jQuery(document).ready(function(){
   // Rendre les liens "candidater" actifs
     jQuery(".link-candidate").click(function(event){
         // Idenfier le lien cliqué
         var clicked_link_id = jQuery(event.target).attr("id");

         // Ecrire la réf. de l'annonce dans le champ ref
         jQuery("#edit-submitted-reference-du-poste-reference-poste").val(clicked_link_id);
         jQuery("#edit-submitted-reference-du-poste-reference-poste").css("border", "solid 1px green");

         // placer le focus sur la civilité
         jQuery("#edit-submitted-vous-concernant-nom").focus();
       });

   // get the links of top menu
   /*var contenus= new Array();
   var positions = new Array();

   //Récupère le contenu et les positions
   jQuery(".menu-name-menu-menu-commodit-haut ul li a").each(function(index){
       contenus[index]=jQuery(this).text();
       var position = jQuery(this).position();
       //alert(position.left+" "+position.top);
       positions[index] = position.left;
   });

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
