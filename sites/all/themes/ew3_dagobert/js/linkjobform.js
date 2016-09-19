jQuery(document).ready(function(){
   //Récupère toutes les références de poste
   var post_ref = new Array();
   jQuery(".link-candidate").each(function(index) {
        post_ref[index]= jQuery(this).attr("id");
   });

   // Rendre les liens "candidater" actifs
     jQuery(".link-candidate").click(function(event){
         // Idenfier le lien cliqué
         var clicked_link_id = jQuery(event.target).attr("id");
         // Ecrire la réf. de l'annonce dans le champ ref
         jQuery("#edit-submitted-reference-du-poste-reference-poste").val(clicked_link_id);
         jQuery("#edit-submitted-reference-du-poste-reference-poste").css("border", "solid 1px green");

         // placer le focus sur la civilité
         jQuery("#edit-submitted-reference-du-poste-reference-poste").focus();
       });
       
       jQuery("#edit-submitted-reference-du-poste-reference-poste").focusout(function(event){
           var val_post_ref = jQuery("#edit-submitted-reference-du-poste-reference-poste").val();
            if(jQuery.inArray(val_post_ref,post_ref)==-1){
                jQuery("#edit-submitted-reference-du-poste-reference-poste").val("");
		alert("Vous devez impérativement donner la référence exacte du poste auquel vous souhaitez postuler. Pour ce faire, le plus simple est de cliquer sur l'un des liens \"Candidater en ligne\" de haut de page.");
            }
            
       });


});
