<?php
/**
 * @file
 * Admin form functions for Islandora Downloadable Datastreams.
 */
/**
 * Admin form for Islandora Downloadable Datastreams.
 */
function islandora_downloadable_datastreams_admin_form($form, $form_settings) {
print("hi hi");
  module_load_include('inc', 'islandora', 'includes/utilities');
  $all_cmodels = islandora_get_content_models();
  $already_chosen = variable_get('islandora_downloadable_datastreams_selected_cmodels', array('islandora:sp_large_image_cmodel', 'islandora:bookCModel', 'islandora:newspaperIssueCModel'));
  $selected_rows = drupal_map_assoc($already_chosen);

  $form['islandora_downloadable_datastreams_image_dsid'] = array(
    '#title' => t('Image datastream to make downloadable'),
    '#type' => 'textfield',
    '#size' => 60,
    '#default_value' => variable_get('islandora_downloadable_datastreams_image_dsid', 'JP2'),
    '#description' => t('The datastream to provide a download link to.'),
    '#maxlength' => 255,
  );

  $form['islandora_downloadable_datastreams_label'] = array(
    '#title' => t('Label for download block'),
    '#type' => 'textfield',
    '#size' => 60,
    '#default_value' => variable_get('islandora_downloadable_datastreams_label', 'Download'),
    '#description' => t('The linked text for the download block.'),
    '#maxlength' => 255,
  );


  $form['content_model_wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configure which content models will display the download block.'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['content_model_wrapper']['downloadable_table'] = array(
    '#type' => 'tableselect',
    '#title' => t('Enable custom pathauto settings for these content models'),
    '#tree' => TRUE,
    '#multiple' => TRUE,
    '#header' => array(
      'label' => array('data' => t('Content-Model')),
    ),
    '#default_value' => $selected_rows,
  );
  $options = array();
  foreach ($all_cmodels as $cmodel) {
    $pid = $cmodel['pid'];
    $label = $cmodel['label'];
    $options[$pid] = array('label' => array('data' => $label));
  }
  $form['content_model_wrapper']['downloadable_table']['#options'] = $options;
  $form['actions'] = array(
    '#type' => 'actions',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configuration'),
    '#weight' => 0,
  );
  return $form;
}
/**
 * Drupal form validation handler.
 *
 * @param array $form
 *   The Drupal form definition.
 * @param array $form_state
 *   The Drupal form state.
 */
function islandora_downloadable_datastreams_admin_form_validate(array $form, array &$form_state) {
  if (!array_keys(array_filter($form_state['values']['downloadable_table']))) {
    form_set_error(
      'downloadable_table',
      t("Please select at least one content model to display the download block on.")
    );
  }
}
/**
 * Submit handler for admin form.
 */
function islandora_downloadable_datastreams_admin_form_submit(array $form, array &$form_state) {
  $enabled = array_keys(array_filter($form_state['values']['downloadable_table']));
  variable_set('islandora_downloadable_datastreams_selected_cmodels', $enabled);
  variable_set('islandora_downloadable_datastreams_image_dsid', $form_state['values']['islandora_downloadable_datastreams_image_dsid']);
  variable_set('islandora_downloadable_datastreams_label', $form_state['values']['islandora_downloadable_datastreams_label']);
  drupal_set_message(t("Configuration saved."));
}
