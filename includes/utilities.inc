<?php
/**
 * @file
 * Utility functions
 */

/**
 * Determine if the object has a Content model we want to show badges on.
 *
 * @param \AbstractObject $object
 *   The object we are viewing.
 *
 * @return bool
 *   Whether $object has a content model to show badges for.
 */
function islandora_downloadable_datastreams_show_for_cmodel(AbstractObject $object) {
  $show_cmodels = variable_get('islandora_downloadable_datastreams_selected_cmodels', array('islandora:sp_large_image_cmodel', 'islandora:bookCModel', 'islandora:newspaperIssueCModel'));
  return (array_intersect($object->models, $show_cmodels) == TRUE);
}
