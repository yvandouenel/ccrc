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

  
});
